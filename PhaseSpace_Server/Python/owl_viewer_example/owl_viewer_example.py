#########################################
# Copyright Phasespace, Inc 2020
#########################################

import sys
import time
import math
import optparse

from PyQt4.QtCore import *
from PyQt4.QtGui import *
from PyQt4.QtOpenGL import *

from OpenGL.GL import *
from OpenGL.GLU import *

import owl

# viewport camera
class GLCamera:
    def __init__(self):
        self.target = QVector3D(0.0, 0.0, 0.0)
        self.angley = 0
        self.anglex = 45
        self.radius = 20
        return

    def pos(self):
        a = math.radians(self.anglex)
        b = math.radians(self.angley)
        x = self.target.x() + self.radius * math.sin(a) * math.cos(b)
        y = self.target.y() + self.radius * math.cos(a)
        z = self.target.z() + self.radius * math.sin(a) * math.sin(b)
        return QVector3D(x,y,z)

    def gluLookAt(self):
        p = self.pos()
        gluLookAt(p.x(), p.y(), p.z(),
                  self.target.x(), self.target.y(), self.target.z(),
                  0.0, 1.0, 0.0)
        return

    def look(self):
        v = self.target - self.pos()
        v.normalize()
        return v

    def right(self):
        v = QVector3D.crossProduct(self.look(), QVector3D(0, 1, 0))
        v.normalize()
        return v

    def up(self):
        v = QVector3D.crossProduct(self.look(), self.right())
        v.normalize()
        return v
    pass##

#
def convert_to_glmatrix(pos, quat):
    m = [1,0,0,0,
         0,1,0,0,
         0,0,1,0,
         0,0,0,1]

    p4_2 = quat[0]*2;  p5_2 = quat[1]*2;  p6_2 = quat[2]*2;
    xx = p4_2*quat[0]; xy = p4_2*quat[1]; xz = p4_2*quat[2];
    yy = p5_2*quat[1]; yz = p5_2*quat[2];
    zz = p6_2*quat[2];

    sx = quat[3]*p4_2; sy = quat[3]*p5_2; sz = quat[3]*p6_2;

    m[0] =1.0-(yy+zz);  m[4] =    (xy-sz);  m[8] =    (xz+sy);
    m[1] =    (xy+sz);  m[5] =1.0-(xx+zz);  m[9] =    (yz-sx);
    m[2] =    (xz-sy);  m[6] =    (yz+sx);  m[10]=1.0-(xx+yy);
    m[3] =0          ;  m[7] =0          ;  m[11]=0          ;

    m[12] = pos[0]
    m[13] = pos[1]
    m[14] = pos[2]
    m[15] = 1.0
    return m

#
def convert_to_glmatrix_inv(pos, quat):
    m = [1,0,0,0,
         0,1,0,0,
         0,0,1,0,
         0,0,0,1]

    p4_2 = quat[0]*2;  p5_2 = quat[1]*2;  p6_2 = quat[2]*2;
    xx = p4_2*quat[0]; xy = p4_2*quat[1]; xz = p4_2*quat[2];
    yy = p5_2*quat[1]; yz = p5_2*quat[2];
    zz = p6_2*quat[2];

    sx = quat[3]*p4_2; sy = quat[3]*p5_2; sz = quat[3]*p6_2;

    m[0] =1.0-(yy+zz);  m[1] =    (xy-sz);  m[2] =    (xz+sy);
    m[4] =    (xy+sz);  m[5] =1.0-(xx+zz);  m[6] =    (yz-sx);
    m[8] =    (xz-sy);  m[9] =    (yz+sx);  m[10]=1.0-(xx+yy);
    m[3] =0          ;  m[7] =0          ;  m[11]=0          ;

    m[12] = -(m[0]*pos[0] + m[4]*pos[1] + m[8]*pos[2])
    m[13] = -(m[1]*pos[0] + m[5]*pos[1] + m[9]*pos[2])
    m[14] = -(m[2]*pos[0] + m[6]*pos[1] + m[10]*pos[2])
    m[15] = 1.0
    return m

#
def init_grid(xscale=10, yscale=10, xdiv=10, ydiv=10):

    def xline(i):
        glVertex3f(-xscale/2 + xscale/xdiv*i, 0,  yscale/2)
        glVertex3f(-xscale/2 + xscale/xdiv*i, 0, -yscale/2)
        pass
    def yline(i):
        glVertex3f( xscale/2, 0, -yscale/2 + yscale/ydiv*i)
        glVertex3f(-xscale/2, 0, -yscale/2 + yscale/ydiv*i)
        pass

    grid = glGenLists(1)
    glNewList(grid, GL_COMPILE)
    glLineWidth(1)
    glBegin(GL_LINES)
    c = 0.15
    for i in range(xdiv+1):
        if i % 10 != 0:
            glColor4f(c, c, c, c)
            xline(i)
            pass
        pass
    for i in range(ydiv+1):
        if i % 10 != 0:
            glColor4f(c, c, c, c)
            yline(i)
            pass
        pass

    c = 0.25
    for i in range(xdiv+1):
        if i % 10 == 0 and i%100 != 0:
            glColor4f(c, c, c, c)
            xline(i)
            pass
        pass
    for i in range(ydiv+1):
        if i % 10 == 0 and i%100 != 0:
            glColor4f(c, c, c, c)
            yline(i)
            pass
        pass

    c = 1
    for i in range(xdiv+1):
        if i%100 == 0:
            glColor4f(c, c, c, c)
            xline(i)
            pass
        pass
    for i in range(ydiv+1):
        if i%100 == 0:
            glColor4f(c, c, c, c)
            yline(i)
            pass
        pass

    glEnd()
    glEndList()
    return grid

#
def draw_axes(scale):
    s = scale
    glLineWidth(2)
    glBegin(GL_LINES)
    glColor3f(1,0,0) # x - r
    glVertex3f(0,0,0)
    glVertex3f(s,0,0)
    glColor3f(0,1,0) # y - g
    glVertex3f(0,0,0)
    glVertex3f(0,s,0)
    glColor3f(0.2,0.2,1) # z - b
    glVertex3f(0,0,0)
    glVertex3f(0,0,s)
    glEnd()
    return

#
class ViewWidget3D(QGLWidget):
    def __init__(self):
        QGLWidget.__init__(self, None)
        self.setFocusPolicy(Qt.StrongFocus)
        self.lastmousepos = None
        self.camera = GLCamera()
        self.quadric = gluNewQuadric()
        self.mutex = QMutex()
        self.grid = None
        self.mouse_mode = None
        self.mousedown = False
        self.points = {}
        return

    #
    def initializeGL(self):
        QGLWidget.initializeGL(self)
        self.grid = init_grid(100, 100, 100, 100)
        glClearColor(0,0,0,1)
        return
    #
    def resizeGL(self, w, h):
        glViewport(0, 0, w, h)
        return
    #
    def initProjection(self, pick=None):
        glMatrixMode(GL_PROJECTION)
        glLoadIdentity()
        if pick:
            x,y = pick
            y2 = self.height() - y
            gluPickMatrix(x,self.height()-y,2,2,[0, 0, self.width(), self.height()])
        gluPerspective(45, self.width()/float(self.height()), 1, 200000)
        return
    #
    def initModelview(self):
        glMatrixMode(GL_MODELVIEW)
        glLoadIdentity()
        self.camera.gluLookAt()
        return
    #
    def paintGL(self):
        QGLWidget.paintGL(self)

        glRenderMode(GL_RENDER)

        # erase previous frame
        glClear(GL_COLOR_BUFFER_BIT)

        # setup matrices
        self.initProjection()
        self.initModelview()

        # grid
        glPushMatrix()
        glColor4f(1,1,1,1)
        glCallList(self.grid)
        glPopMatrix()

        # axes
        glPushMatrix()
        draw_axes(1)
        glPopMatrix()

        # points
        radius = 0.05
        self.mutex.lock()
        glColor4f(1,1,1,1)
        for id,p in self.points.iteritems():
            if p.cond < 0: continue
            pos, quat = (p.x, p.y, p.z), (1, 0, 0, 0)
            m = convert_to_glmatrix(pos, quat)
            glPushMatrix()
            glMultMatrixf(m)
            gluSphere(self.quadric, radius, 4,4)
            self.renderText(radius, radius, radius, "%d"%(id,))
            #draw_axes(0.1)
            glPopMatrix()
            pass
        self.mutex.unlock()

        return

    #
    def doSelection(self, x, y):
        # enter selection mode
        glSelectBuffer(1024)
        glRenderMode(GL_SELECT)
        glInitNames()
        # setup view matrix
        self.initProjection((x,y))
        self.initModelview()
        #
        self.renderSelection()
        #
        hits = glRenderMode(GL_RENDER)
        self.handleHits(hits)
        pass

    # override
    def renderSelection(self):
        return
    # override
    def handleHits(self, hits):
        return
    #
    def mouseMoveEvent(self, event):
        if self.lastmousepos == None:
            self.lastmousepos = QVector2D(event.x(), event.y())
            return
        newpos = QVector2D(event.x(), event.y())
        dt = newpos - self.lastmousepos
        self.lastmousepos = newpos

        if self.mouse_mode == "pan":
            self.camera.angley += dt.x() / 2
            self.camera.anglex -= dt.y() / 2
            self.camera.anglex = min(max(self.camera.anglex, 0.0001), 180)
            pass
        elif self.mouse_mode == "drag":
            self.camera.target -= dt.x() * self.camera.right() * (self.camera.radius / 120.0)
            self.camera.target -= dt.y() * self.camera.up() * (self.camera.radius / 120.0)
            self.camera.target = QVector3D(self.camera.target.x(), 0, self.camera.target.z())
            pass
        self.update()
        return
    def mousePressEvent(self, event):
        buttons = event.buttons()

        if buttons == Qt.RightButton:
            self.mouse_mode = "pan"
            pass
        elif buttons == Qt.MiddleButton:
            self.mouse_mode = "drag"
            pass
        self.lastmousepos = QVector2D(event.x(), event.y())
        self.mousedown = True
        self.update()
        return
    def mouseReleaseEvent(self, event):
        self.lastmousepos = None
        self.mouse_mode = None
        self.mousedown = False
        self.lastmousepos = None
        self.doSelection(event.x(), event.y())
        self.update()
        return
    def wheelEvent(self, event):
        if(event.delta() > 0):
            self.camera.radius *= 0.8
            self.camera.radius = max(self.camera.radius, 0.5)
        else:
            self.camera.radius *= 1.2
            self.camera.radius = min(self.camera.radius, 1000)
            pass
        self.update()
        return
    def keyReleaseEvent(self, event):
        if event.text() == 'r':
            self.camera = GLCamera()
            pass
        elif event.text() == 'q':
            sys.exit(0)
            pass
        elif event.text() == 'y':
            self.camera.anglex = 0.0001
            pass
        elif event.text() == 'x':
            self.camera.angley = 0
            self.camera.anglex = 90
            pass
        elif event.text() == 'z':
            self.camera.angley = 90
            self.camera.anglex = 90
            pass
        self.update()
        return
    pass##

#
class MainThread(QThread):
    def __init__(self, widget, options, args):
        QThread.__init__(self)
        self.widget = widget
        self.verbose = options.verbose
        self.device = options.device
        pass
    def run(self):
        device = owl.Context()
        device.debug = self.verbose

        # connect
        device.open(self.device)

        # init
        device.initialize("event.markers=1 event.rigids=1 scale=0.001")

        # start data stream
        device.streaming(1)

        # main data loop
        event = None
        while event or (device.isOpen() and device.property("initialized")):
            event = device.nextEvent(1000)
            if not event: continue

            if event.type_id == owl.Type.FRAME:
                try:
                    # send markers to draw widget
                    self.widget.mutex.lock()
                    if "markers" in event:
                        for m in event.markers:
                            print(m)
                            self.widget.points[m.id] = m
                finally:
                    self.widget.mutex.unlock()

            elif event.type_id == owl.Type.CAMERA:
                for camera in event.data:
                    print(camera)
            elif event.type_id == owl.Type.ERROR:
                print(event.name, event.type_id, event.data)
                if event.name == "fatal":
                    raise owl.OWLError(event.data)

            # redraw 3D display
            self.widget.update()

            # prevent use of too much CPU
            time.sleep(0)
            pass
        pass
    pass


main_window = None

#Example
def start(argv, widget_class, widget_args):
    global main_window

    ## parse command line
    parser = optparse.OptionParser()
    parser.add_option("-v", "--verbose", dest="verbose", default=False, action="store_true")
    parser.add_option("-d", "--device", dest="device", default="localhost")
    options, args = parser.parse_args()

    # create QT widgets
    app = QApplication(argv)
    mw = QMainWindow()
    main_window = mw

    widget = widget_class(*widget_args)
    mw.setCentralWidget(widget)
    mw.resize(800,600)
    mw.show()

    # start main thread
    mt = MainThread(widget, options, args)
    mt.start()

    # start main app
    app.exec_()
    return


if __name__ == "__main__":
    start(sys.argv, ViewWidget3D, [])
    pass
