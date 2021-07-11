#pragma warning(disable:4996)
#pragma fenv_access(on)

#include <iostream>
#include <cmath>
#include <cerrno>
#include <cfenv>
#include <cfloat>
#include <cstring>
#include <conio.h>

/*  Source by CPPReference
    Modified For Learn by Rizky Khapidsyah
    I.D.E : VS2019 */

int main() {
    std::cout << "(1,1) cartesian is (" << std::hypot(1, 1) << ',' << std::atan2(1, 1) << ") polar\n";
    std::cout << "hypot(NAN,INFINITY) = " << std::hypot(NAN, INFINITY) << '\n';
    
    errno = 0;
    std::feclearexcept(FE_ALL_EXCEPT);
    std::cout << "hypot(DBL_MAX,DBL_MAX) = " << std::hypot(DBL_MAX, DBL_MAX) << '\n';
    
    if (errno == ERANGE) {
        std::cout << "    errno = ERANGE " << std::strerror(errno) << '\n';
    }
        
    if (std::fetestexcept(FE_OVERFLOW)) {
        std::cout << "    FE_OVERFLOW raised\n";
    }
        
    _getch();
    return 0;
}