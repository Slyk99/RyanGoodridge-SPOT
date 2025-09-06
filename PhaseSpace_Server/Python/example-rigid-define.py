#!/usr/bin/python

#
# Copyright (c) PhaseSpace, Inc 2017
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
# PHASESPACE, INC BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
# IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
# CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#

import owl
import sys

SERVER = '192.168.1.109'

# instantiate context
o = owl.Context()
# connect to server with timeout of 10000000 microseconds
o.open(SERVER, "timeout=10000000")
# initialize session
o.initialize("streaming=1")

#clienttype = o.property("slave")

#Create and define rigid tracker
o.createTracker(0, "rigid")
o.assignMarker(0, 0, "0", "pos=0,407,-7.615")
o.assignMarker(0, 4, "4", "pos=-7.615,282,0")
o.assignMarker(0, 2, "2", "pos=0,157,-7.615")
o.assignMarker(0, 6, "6", "pos=-7.615,32,0")

# main loop
evt = None
while evt or (o.isOpen() and o.property("initialized")):

    # poll for events with a timeout (microseconds)
    evt = o.nextEvent(1000000)
    # nothing received, keep waiting
    if not evt: continue
    #else: print evt

    # process event
    if evt.type_id == owl.Type.FRAME:
        # print markers
        if "markers" in evt:
            for m in evt.markers: 
                if m.cond > 0:
                    print(m.x, m.y, m.z)
        if "rigids" in evt:
            for r in evt.rigids: 
                print(r)
        # handle errors
        #print(evt.name, evt.data)
        if evt.name == "fatal":
            break
    elif evt.name == "done":
        # done event is sent when master connection stops session
        print("done")
        break
# end main loop

# end session
o.done()
# close socket
o.close()
