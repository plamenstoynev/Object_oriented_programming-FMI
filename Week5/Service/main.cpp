#include <iostream>
#include "Service.h"
#include "BrokenAppliance.h"

int main(){
    bool productsCanFix[9] = {true, false, true, true , false, true, false, true, false};
    Technic technics[30];
    Service service(technics);
    BrokenAppliance brokenAppliance(Category::TV, 1000, true);
    Client client("Ivan", brokenAppliance);
    Technic technic("Plamen", "089761234", productsCanFix);
    service.addTechnic(technic);
    Technic technicForClient = service.technicForTheClient(client);

    BrokenAppliance brokenAppliance2(Category::PC, 2000, false);
    Client client2("Petar", brokenAppliance2);
    Technic technic2("Georgi", "089761235", productsCanFix);
    service.addTechnic(technic2);
    Technic technicForClient2 = service.technicForTheClient(client2);


    std::cout << technicForClient.getID() << std::endl;
    std::cout << technicForClient2.getID() << std::endl;

    service.removeTechnic("089761235");
    return 0;
}