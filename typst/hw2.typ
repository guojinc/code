#import "@preview/pintorita:0.1.1"

#set page(height: auto, width: auto, fill: white, margin: 2em)
#set text(fill: black)

#show raw.where(lang: "pintora"): it => pintorita.render(it.text)

= UML Class Diagram: Aircraft Infomation Management System

```pintora
classDiagram
    class AircraftInformationSystem {
        -List<Aircraft> aircraftList
        -List<Pilot> pilotList
        -List<Manufacturer> manufacturerList
        +addAircraft(aircraft: Aircraft): void
        +addPilot(pilot: Pilot): void
        +addManufacturer(manufacturer: Manufacturer): void
        +getAircraftById(id: int): Aircraft
        +getPilotsByAircraft(aircraftId: int): List<Pilot>
        +getManufacturerByAircraft(aircraftId: int): Manufacturer
    }

    class Aircraft {
        -int aircraftId
        -string model
        -float maxSpeed
        -date manufactureDate
        +getBasicInfo(): string
    }

    class J20 {
        -int missileCount
        +getJ20Details(): string
    }

    class Y20 {
        -float maxPayload
        +getY20Details(): string
    }

    class Pilot {
        -int pilotId
        -string name
        -int age
        -Aircraft assignedAircraft
        +getPilotInfo(): string
    }

    class Manufacturer {
        -string companyName
        -string location
        +getManufacturerInfo(): string
    }

    %% Class relationships
    AircraftInformationSystem "1" --* "many" Aircraft 
    AircraftInformationSystem "1" --* "many" Pilot 
    AircraftInformationSystem "1" --* "many" Manufacturer 
    
    Aircraft "1" o-- "many" Pilot 
    Aircraft "1" --> "1" Manufacturer 
    
    Aircraft <|-- J20
    Aircraft <|-- Y20

```
