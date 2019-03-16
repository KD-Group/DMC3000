%module motion
%{
#include "motion.h"
#include "LTDMC.h"
%}

%include "std_string.i"
%include "std_vector.i"
namespace std {
   %template(vectori) vector<int>;
   %template(vectord) vector<double>;
};

%include "motion.h"
