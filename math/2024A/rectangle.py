import pybullet as p
import time
import pybullet_data
import math

# 连接到 PyBullet 仿真
physicsClient = p.connect(p.GUI)

# 设置搜索路径以加载默认模型
# p.setAdditionalSearchPath(pybullet_data.getDataPath())

# # 确认 plane.urdf 文件存在于搜索路径中
# plane_urdf_path = pybullet_data.getDataPath() + "/plane.urdf"
# print(f"Loading URDF from: {plane_urdf_path}")

# # 加载基础平面（作为参考）
# planeId = p.loadURDF(plane_urdf_path)

# 创建长方体物块
box_half_extents = [0.1, 0.05, 0.05]  # 长方体的半尺寸
box_collision_shape = p.createCollisionShape(p.GEOM_BOX, halfExtents=box_half_extents)
box_visual_shape = p.createVisualShape(p.GEOM_BOX, halfExtents=box_half_extents, rgbaColor=[1, 0, 0, 1])

# 初始位置和方向
start_pos = [0, 0, 0]
start_orientation = p.getQuaternionFromEuler([0, 0, 0])

# 创建多体系统
box_id = p.createMultiBody(baseMass=1,
                           baseCollisionShapeIndex=box_collision_shape,
                           baseVisualShapeIndex=box_visual_shape,
                           basePosition=start_pos,
                           baseOrientation=start_orientation)

# 创建铰链节点
hinge_joint_axis = [0, 0, 1]  # 铰链旋转轴
hinge_joint_pivot_in_a_1 = [0.1, 0, 0]  # 第一个铰链在长方体上的位置
hinge_joint_pivot_in_a_2 = [-0.1, 0, 0]  # 第二个铰链在长方体上的位置
hinge_joint_pivot_in_b = [0, 0, 0]  # 铰链在世界坐标系中的位置

# 添加第一个铰链节点
hinge_id_1 = p.createConstraint(parentBodyUniqueId=box_id,
                                parentLinkIndex=-1,
                                childBodyUniqueId=-1,
                                childLinkIndex=-1,
                                jointType=p.JOINT_REVOLUTE,
                                jointAxis=hinge_joint_axis,
                                parentFramePosition=hinge_joint_pivot_in_a_1,
                                childFramePosition=hinge_joint_pivot_in_b)

# 添加第二个铰链节点
hinge_id_2 = p.createConstraint(parentBodyUniqueId=box_id,
                                parentLinkIndex=-1,
                                childBodyUniqueId=-1,
                                childLinkIndex=-1,
                                jointType=p.JOINT_REVOLUTE,
                                jointAxis=hinge_joint_axis,
                                parentFramePosition=hinge_joint_pivot_in_a_2,
                                childFramePosition=hinge_joint_pivot_in_b)

# 仿真开始
theta = 32 * math.pi
for i in range(10000):
    # 更新角度（随时间增加）
    theta -= i * 0.01  # 每步旋转的角度增量

    # 计算 X 和 Y 坐标（根据螺线方程）
    x = 0.05 * theta * math.cos(theta)
    y = 0.05 * theta * math.sin(theta)

    # 更新长方体的位置
    p.resetBasePositionAndOrientation(box_id, [x, y, 0.5], start_orientation)

    # 步进仿真
    p.stepSimulation()
    time.sleep(1./240.)

# 断开连接
p.disconnect()