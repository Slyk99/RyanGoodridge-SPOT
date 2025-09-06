#!/usr/bin/python

#
# Copyright (c) PhaseSpace, Inc 2019
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
# PHASESPACE, INC BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
# IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
# CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#

from __future__ import print_function
import owl
import sys

def padHex(s):
    if len(s[2:]) < 2: return s[2:].zfill(2)
    else: return s[2:]

SERVER = sys.argv[1]
options = "event.hub=1 event.ttlframecount=1 streaming=1"
if len(sys.argv) > 2:
    for n in range (2, len(sys.argv)):
        options += " " +  str(sys.argv[n])

# instantiate context
o = owl.Context()
# connect to server with timeout of 10000000 microseconds
o.open(SERVER, "timeout=10000000")
# initialize session
o.initialize(options)

# main loop
evt = None
while evt or (o.isOpen() and o.property("initialized")):

    # poll for events with a timeout (microseconds)
    evt = o.nextEvent(1000000)
    # nothing received, keep waiting
    if not evt: continue
    # else: print evt

    if evt.type_id == owl.Type.FRAME:
        # print markers
        if "ttlframecount" in evt:
            print( "time=" + str(evt.time) +" ttl_frame_count=" + str(evt.ttlframecount[0]))
        if "hub" in evt:
            print( " Inputs=" + str(len(evt.hub)) + ":" )
            for i in evt.hub:
                size = len(i.data)
                if size > 6:
                    ttl_input = i.data[0]
                    payload_page = i.data[1]
                    print( "  size(bytes)=" + str(size) + " input=" + str(ttl_input) + " payload_page=" + str(payload_page))
                    for d in range(2, size): print(padHex(hex(i.data[d])), end=" ")
                    print("\n")
    elif evt.type_id == owl.Type.ERROR:
        # handle errors
        print(evt.name, evt.data)
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
