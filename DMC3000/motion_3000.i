%module motion_3000
%{
#include "motion_3000.h"
#include "LTDMC.h"
%}

%include "std_string.i"
%include "std_vector.i"
namespace std {
   %template(vectori) vector<int>;
   %template(vectord) vector<double>;
};

%include "motion_3000.h"
