#import "@preview/pintorita:0.1.1"

#set page(height: auto, width: auto, fill: white, margin: 2em)
#set text(fill: black)

#show raw.where(lang: "pintora"): it => pintorita.render(it.text)

= UML Class Diagram: Autonomous Driving System
```pintora
classDiagram

class AutonomousDrivingSystem {
    -currentStatus : CurrentStatus
    -pathPlanningModule : PathPlanningModule
    -drivingActionModule : DrivingActionModule
    -infoDisplayModule : InfoDisplayModule
    -drivingRecordModule : DrivingRecordModule
    +getCurrentStatus() : CurrentStatus
    +getPathPlanningModule() : PathPlanningModule
    +getDrivingActionModule() : DrivingActionModule
    +getInfoDisplayModule() : InfoDisplayModule
    +getDrivingRecordModule() : DrivingRecordModule
}

class CurrentStatus {
    -sensorData : SensorData
    -position : Position
    +getSensorData() : SensorData
    +getPosition() : Position
}

class SensorData {
    -speed : double
    -steeringAngle : double
    -cameraData : String
    -lidarData : String
    +getSpeed() : double
    +getSteeringAngle() : double
    +getCameraData() : String
    +getLidarData() : String
}

class Position {
    -longitude : double
    -latitude : double
    +getLongitude() : double
    +getLatitude() : double
}

class PathPlanningModule {
    -routes : List<DrivingPath>
    +planPath(start : Position, destinations : List<Position>) : void
    +getFastestRoute() : DrivingPath
    +getShortestRoute() : DrivingPath
    +getCurrentRoute() : DrivingPath
    +getNextWaypoint() : Position
    +getDistanceAndTravelTime() : (double, double)
    +getRoutes() : List<DrivingPath>
}

class DrivingPath {
    -waypoints : List<Position>
    +getDistance() : double
    +getTravelTime() : double
    +getWaypoints() : List<Position>
}

class DrivingActionModule {
    -roadCondition : String
    -drivingAction : String
    +calculateRoadCondition() : void
    +determineDrivingAction(roadCondition: String, speed: double, steeringAngle: double, destination: Position) : String
    +getCurrentDrivingAction() : String
    +getRoadCondition() : String
    +getDrivingAction() : String
}

class InfoDisplayModule {
    +displayCurrentPosition() : void
    +displayPathPlanning() : void
    +displayRemainingDistance() : void
    +displayRemainingTime() : void
}

class DrivingRecordModule {
    -drivingRecords : List<DrivingRecord>
    +recordDriving() : void
    +replayDrivingRecord() : void
    +getDrivingRecords() : List<DrivingRecord>
}

class DrivingRecord {
    -actions : List<String>
    -timestamp : Date
    +getActions() : List<String>
    +getTimestamp() : Date
}

%% Class relationships
AutonomousDrivingSystem --> CurrentStatus
AutonomousDrivingSystem --> PathPlanningModule
AutonomousDrivingSystem --> DrivingActionModule
AutonomousDrivingSystem --> InfoDisplayModule
AutonomousDrivingSystem --> DrivingRecordModule

CurrentStatus --> SensorData
CurrentStatus --> Position
PathPlanningModule "1" --> "0..*" DrivingPath
DrivingRecordModule "1" --> "0..*" DrivingRecord
```