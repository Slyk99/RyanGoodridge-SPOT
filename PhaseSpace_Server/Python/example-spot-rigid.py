#!/usr/bin/python

#==============================================================================
# PREAMBLE
#==============================================================================

import owl
import sys
import csv
import datetime
import time

#==============================================================================
# DEFINE PARAMETERS
#==============================================================================

# Set the IP address of the server
SERVER = '192.168.1.109'
TIMEOUT = 10000000
STREAMING = 1  # 0 to disable, 1 for UDP, 2 for TCP, 3 for TCP Broadcast
FREQUENCY = 100  # in Hz

#==============================================================================
# INITIALIZE STREAMING SERVER
#==============================================================================

# Instantiate context
owl_context = owl.Context()

# Connect to server with timeout of 10000000 microseconds
owl_context.open(SERVER, "timeout="+str(TIMEOUT))

# Initialize session
owl_context.initialize("streaming="+str(STREAMING))  # Set to UDP
owl_context.initialize("frequency=1"+str(FREQUENCY))  # Set to desired rate

#==============================================================================
# SET UP RIGID BODY TRACKERS
#==============================================================================

# Create the tracker for RED, BLACK, and BLUE rigid bodies
tracker_ID_RED = 0
tracker_ID_BLACK = 2
tracker_ID_BLUE = 3

# Create and define rigid tracker for RED
owl_context.createTracker(tracker_ID_RED, "rigid", "RED_rigid")
owl_context.assignMarker(tracker_ID_RED, 0, "0", "pos=125.509767,143.875167,0")
owl_context.assignMarker(tracker_ID_RED, 6, "6", "pos=125.509767,-135.624833,0")
owl_context.assignMarker(tracker_ID_RED, 4, "4", "pos=-154.990233,-135.624833,0")
owl_context.assignMarker(tracker_ID_RED, 2, "2", "pos=-153.490233,144.375167,0")

# Create and define rigid tracker for BLACK
owl_context.createTracker(tracker_ID_BLACK, "rigid", "BLACK_rigid")
owl_context.assignMarker(tracker_ID_BLACK, 13, "13", "pos=130.251807,141.800150,0")
owl_context.assignMarker(tracker_ID_BLACK, 11, "11", "pos=130.751807,-135.699850,0")
owl_context.assignMarker(tracker_ID_BLACK, 9, "9", "pos=-146.748193,-135.199850,0")
owl_context.assignMarker(tracker_ID_BLACK, 15, "15", "pos=-146.748193,143.300150,0")

# Create and define rigid tracker for BLUE
owl_context.createTracker(tracker_ID_BLUE, "rigid", "BLUE_rigid")
owl_context.assignMarker(tracker_ID_BLUE, 16, "16", "pos=140.000177,152.096588,0")
owl_context.assignMarker(tracker_ID_BLUE, 22, "22", "pos=140.500177,-125.403412,0")
owl_context.assignMarker(tracker_ID_BLUE, 20, "20", "pos=-136.999823,-124.903412,0")
owl_context.assignMarker(tracker_ID_BLUE, 18, "18", "pos=-136.999823,153.596588,0")

#==============================================================================
# START MAIN LOOP
#==============================================================================

try:
    # Create a filename based on the current datetime
    filename = datetime.datetime.now().strftime("RED_rigid_%Y%m%d_%H%M%S.csv")

    # Create an empty event
    event = None

    # Start the loop
    while event or (owl_context.isOpen() and owl_context.property("initialized")):

        # Poll for events with a timeout (microseconds)
        event = owl_context.nextEvent(1000000)

        # If nothing received, keep waiting
        if not event: continue

        # If something received, process event
        if event.type_id == owl.Type.FRAME:

            # # Print markers
            # if "markers" in event:
            #     for m in event.markers: 
            #         if m.cond > 0:
            #             print(m.x, m.y, m.z)

            # Find any rigid bodies    
            if "rigids" in event:
                for r in event.rigids: 
                
                    # Initialize data for RED, BLACK, and BLUE rigid bodies
                    red_data = [0, 0, 0, 0, 0, 0]
                    black_data = [0, 0, 0, 0, 0, 0]
                    blue_data = [0, 0, 0, 0, 0, 0]

                    # Save the position of the RED rigid body and attitude
                    if r.id == tracker_ID_RED:
                        red_data = [r.pose[0], r.pose[1], r.pose[2], r.pose[3], r.pose[4], r.pose[5]]

                    # Save the position of the BLACK rigid body and attitude
                    if r.id == tracker_ID_BLACK:
                        black_data = [r.pose[0], r.pose[1], r.pose[2], r.pose[3], r.pose[4], r.pose[5]]

                    # Save the position of the BLUE rigid body and attitude
                    if r.id == tracker_ID_BLUE:
                        blue_data = [r.pose[0], r.pose[1], r.pose[2], r.pose[3], r.pose[4], r.pose[5]]

                    # Open and append the data to a CSV
                    with open(filename, mode='a', newline='') as csv_file:
                        csv_writer = csv.writer(csv_file, delimiter=',', quotechar='"', quoting=csv.QUOTE_MINIMAL)
                        csv_writer.writerow(red_data + black_data + blue_data)

            # Handle errors
            if event.name == "fatal":
                break

        # Handle done event
        elif event.name == "done":
            # Done event is sent when master connection stops session
            break

        # Sleep to maintain the desired frequency
        time.sleep(1 / FREQUENCY)

except KeyboardInterrupt:
    print("Interrupted by user. Closing connection...")

finally:
    #==============================================================================
    # CLOSE CONNECTION
    #==============================================================================

    # End session
    owl_context.done()

    # Close socket
    owl_context.close()
