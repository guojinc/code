

USE student;

CREATE TABLE IF NOT EXISTS STU(
  stuid INT PRIMARY KEY AUTO_INCREMENT COMMENT '编号，主键自增',
  sname VARCHAR(50) NOT NULL COMMENT '姓名',
  gender VARCHAR(4) DEFAULT '男' COMMENT '性别',
  address VARCHAR(300) COMMENT '地址',
  birthday DATE COMMENT '生日',`student`
  classname VARCHAR(50) COMMENT '班级',
  note LONGTEXT COMMENT '备注'	
);
INSERT INTO STU(sname,gender,address,birthday,classname,note)
VALUES('张飞','男','北京','2002-12-11','python8班','辅助'),
('马超','男','兰州','2002-1-11','python8班','战士'),
('关羽','男','运城','2002-2-11','python8班','战士'),
('赵云','男','常山','2002-3-12','python2班','打野'),
('黄忠','男','荆州','2002-4-15','python2班','射手'),
('刘备','男','户县','2002-5-15','python1班','打野'),
('曹操','男','洛阳','2002-2-22','python1班','战士'),
('许褚','男','长安','2002-3-21','python8班','打野');

UPDATE STU SET sname='貂蝉',gender='女',address='米脂',note='法师' WHERE stuid=6;

DELETE FROM STU WHERE stuid=7;
SELECT * FROM STU;