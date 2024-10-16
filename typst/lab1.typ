#import "@preview/pintorita:0.1.1"

#set page(height: auto, width: auto, fill: white, margin: 2em)
#set text(fill: black)

#show raw.where(lang: "pintora"): it => pintorita.render(it.text)

= UML Class Diagram: Campus Activity Management System for NPU
```pintora
classDiagram
    class CampusActivityManagementSystem {
        +userManagement: UserManagementSubsystem
        +activityManagement: ActivityManagementSubsystem
    }

    class UserManagementSubsystem {
        +viewAllUsers(): List<User>
        +addUser(user: User): void
        +deleteUser(userId: String): void
        +modifyUser(user: User): void
        +checkUser(userId: String): User
    }

    class ActivityManagementSubsystem {
        +viewAllActivities(): List<Activity>
        +addActivity(activity: Activity): void
        +deleteActivity(activityId: String): void
        +modifyActivity(activity: Activity): void
        +checkActivity(activityId: String): Activity
        +screenActivitiesByTime(startTime: Date, endTime: Date): List<Activity>
        +addTeamToActivity(activityId: String, team: Team): void
        +removeTeamFromActivity(activityId: String, teamId: String): void
    }

    class User {
        -String name
        -String id
        -String phoneNumber
        -String email
    }

    class Student {
        -String studentNumber
        -String gender
        -String grade
        -String department
    }

    class Teacher {
        -String jobNumber
        -String college
    }

    class Organizer {
        -String departmentName
    }

    class Activity {
        -String id
        -String name
        -Date startTime
        -Date endTime
        -String description
        -String site
    }

    class LiteraryArtActivity {
        -String literaryType
    }

    class LectureActivity {
        -List<String> speakers
    }

    class PartyDayActivity {
        -String theme
        -String classification
    }

    class Team {
        -String teamId
        -String teamName
        -String college
    }

    %% Class relationships
    CampusActivityManagementSystem "1" --> "+UserManagementSubsystem 1" UserManagementSubsystem
    CampusActivityManagementSystem "1" --> "+ActivityManagementSubsystem 1" ActivityManagementSubsystem 

    UserManagementSubsystem "1" o-- "User 0...*" User
    User <|-- Student
    User <|-- Teacher
    User <|-- Organizer

    ActivityManagementSubsystem "1" o-- "0...*Activity" Activity 
    Activity <|-- LiteraryArtActivity
    Activity <|-- LectureActivity
    Activity <|-- PartyDayActivity

    Activity "1" o-- Organizer : +1 Activity
    Activity "1" o-- "+0...*Teacher" Teacher
    Activity "1" o-- "+0...*Team" Team
    Team "0...*Team" o-- "+1" Student
    Teacher "1" o-- "+0...*Team" Team
```