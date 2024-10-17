import numpy as np


class point():
    def __init__(self, a, b, coordinate = 'polar'):
        if coordinate == 'polar':
            self.r = a
            self.theta = b
            self.x = a * np.cos(b)
            self.y = a * np.sin(b)
        elif coordinate == 'dicar':
            self.x = a
            self.y = b
            self.r = np.sqrt(a * a + b * b)
            self.theta = np.arctan(b / a)
    def distance(self, point):
        return np.sqrt((self.x - point.x)**2 + (self.y - point.y)**2) 

    def __repr__(self):
        return f'{self.x} {self.y}\n'


class rectangle():
    theta = np.arctan(6 / 11)
    d = np.sqrt(15**2 + 27.5**2) / 100
    def __init__(self, last : point, Next : point):
        self.last = last
        self.Next = Next
        self.last_x, self.last_y = last.x, last.y
        self.Next_x, self.Next_y = Next.x, Next.y
        
        
        A = self.last_x - self.Next_x
        B = self.last_y - self.Next_y
        c = 0.275 / np.sqrt(A**2 + B**2)
        d = 0.15 / np.sqrt(A**2 + B**2)
        self.vertical_a = point(self.last_x + c * A + d * B, self.last_y + c * B - d * A, 'dicar')
        self.vertical_b = point(self.Next_x - c * A + d * B, self.Next_y - c * B - d * A, 'dicar')
        self.vertical_c = point(self.Next_x - c * A - d * B, self.Next_y - c * B + d * A, 'dicar')
        self.vertical_d = point(self.last_x + c * A - d * B, self.last_y + c * B + d * A, 'dicar')

        self.vertices = [self.vertical_a, self.vertical_b, self.vertical_c, self.vertical_d]


    def __str__(self):
        return f'{self.last.r} {self.last.theta}\t{self.Next.r} {self.Next.theta}'

    def iscollision(self, rect):
        
        def get_axes(rect):
            axes = []
            for i in range(len(rect.vertices)):
                p1 = rect.vertices[i]
                p2 = rect.vertices[(i + 1) % len(rect.vertices)]
                edge = np.array([p2.x - p1.x, p2.y - p1.y])
                normal = np.array([-edge[1], edge[0]])
                axes.append(normal / np.linalg.norm(normal))
            return axes

        def project(rect, axis):
            dots = [vertex.x * axis[0] + vertex.y * axis[1] for vertex in rect.vertices]
            return [min(dots), max(dots)]

        axes = get_axes(self) + get_axes(rect)
        for axis in axes:
            proj1 = project(self, axis)
            proj2 = project(rect, axis)
            if proj1[1] < proj2[0] or proj2[1] < proj1[0]:
                return False
        return True

