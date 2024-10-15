#import "@preview/pintorita:0.1.1"

#set page(height: auto, width: auto, fill: white, margin: 2em)
#set text(fill: black)

#show raw.where(lang: "pintora"): it => pintorita.render(it.text)

= UML Class Diagram: Tourism Information System

```pintora
classDiagram
  class TouristInformationSystem {
    - products: List<TourismProduct>
    - routes: List<TouristRoute>
    + addProduct(product: TourismProduct): void
    + addRoute(route: TouristRoute): void
    + displayProducts(): void
    + displayRoutes(): void
    + searchProduct(dep: String, dest: String): List<TourismProduct>
    + searchRouteByAttraction(attraction: String): List<TouristRoute>
    + searchRouteByPerson(person: ResponsiblePerson): List<TouristRoute>
  }

  class TourismProduct {
    - code: String
    - title: String
    - departure: String
    - destination: String
    - touristRoute: TouristRoute
    - sellingPrice: double
    - travelAgencyName: String
    + addProduct(): void
    + lookUpProduct(dep: String, dest: String): TourismProduct
  }

  class DomesticTourism {
    <<inherits from TourismProduct>>
  }

  class PeripheralTourism {
    <<inherits from TourismProduct>>
    - productFeatureDescription: String
  }

  class OutboundTourism {
    <<inherits from TourismProduct>>
    - stayOfDays: int
  }

  class CruiseTourism {
    <<inherits from TourismProduct>>
    - cruiseCompany: String
    - stayOfDays: int
  }

  class TouristRoute {
    - routeCode: String
    - name: String
    - responsiblePerson: ResponsiblePerson
    - touristAttractions: List<TouristAttraction>
  }

  class ResponsiblePerson {
    - id: String
    - name: String
    - homePhoneNumber: String
    - qq: String
    - email: String
  }

  class TouristAttraction {
    - name: String
    - type: String
    - province: String
  }

  TouristInformationSystem "1" *-- "0..*" TourismProduct 
  TouristInformationSystem "1" *-- "0..*" TouristRoute 
  
  TourismProduct <|-- DomesticTourism
  TourismProduct <|-- PeripheralTourism
  TourismProduct <|-- OutboundTourism
  TourismProduct <|-- CruiseTourism
  
  TourismProduct "1" -- "0..*" TouristRoute 
  TouristRoute "1" o-- "1" ResponsiblePerson 
  TouristRoute "1" *-- "0..*" TouristAttraction 

```