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

    std::cout << technicForClient.getID() << std::endl;

    return 0;
}