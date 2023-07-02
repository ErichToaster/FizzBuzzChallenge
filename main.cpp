	                   #include <iostream>
	                    #include <vector>
	                    #include <regex>
	                    struct sextuplet
{
	                        bool fizz
;	                     //multiple of 3
	                        bool buzz
;	                     //multiple of 5
	                        bool rizz
;	                     //multiple of 7
	                        bool jazz
;	                    //multiple of 11
	                        bool dizz
;	                    //divisor of 120
	                       bool prizz
;	         //last prime before next rizz or jazz
};	                      bool isPrime
(	                          int n
){	//insert "return true;" here to test Prizz functionality
	                      bool prime =
(	                          n > 1
);	                     int divisor = 2
;	                          while
(	                        prime &&
(	                 divisor * divisor <= n
)){	                         prime =
(	                    n % divisor != 0
);	                       divisor ++
;}	                      return prime
;}	                        int main
(){	              //for the sake of simplicity,
	             //none of this is zero-indexed.
	        //Instead, the index of a vector matches
	             //the number it corresponds to.
	           //the first element, 0, is unused,
	        //and instead, 1 is treated as the first.
	      //this also applies to 'i' in both for-loops.
	                 int amountToPrint = 100
;	            std::vector<sextuplet> VEC_bools
(	                    amountToPrint+1,
{	                    0, 0, 0, 0, 0, 0
});	            bool PrizzWasAlreadySaved = false
;	                           for
(	                  int i = amountToPrint
;	                          i > 0
;	                           i--
){	                  VEC_bools[i].fizz = !
(	                          i % 3
);	                  VEC_bools[i].buzz = !
(	                          i % 5
);	                  VEC_bools[i].rizz = !
(	                          i % 7
);	                  VEC_bools[i].jazz = !
(	                         i % 11
);	                  VEC_bools[i].dizz = !
(	                         120 % i
);	             //if this is prime, print Prizz
	    //(if it wasn't already printed in this context)
	              VEC_bools[i].prizz = isPrime
(	                            i
)	                 & !PrizzWasAlreadySaved
;	       PrizzWasAlreadySaved += VEC_bools[i].prizz
;	                 bool thisIsRizzOrJazz =
	           VEC_bools[i].rizz + VEC_bools[i].jazz
;	       //only preserve PWAS if this isn't R or J.
	            //Otherwise, the next number will
	      //be getting a new context, so reset to zero.
	                 PrizzWasAlreadySaved =
	        PrizzWasAlreadySaved & !thisIsRizzOrJazz
;}	            std::vector<std::string> Assets =
{	   "", "Fizz", "Buzz", "Rizz", "Jazz", "Dizz", "Prizz"
};	                std::string toPrint = ""
;	                           for
(	                        int i = 1
;	                   i <= amountToPrint
;	                           i++
){	                toPrint += std::to_string
(	                            i
);	                     toPrint += "\r"
;	         toPrint += Assets[VEC_bools[i].fizz*1]
;	         toPrint += Assets[VEC_bools[i].buzz*2]
;	         toPrint += Assets[VEC_bools[i].rizz*3]
;	         toPrint += Assets[VEC_bools[i].jazz*4]
;	         toPrint += Assets[VEC_bools[i].dizz*5]
;	         toPrint += Assets[VEC_bools[i].prizz*6]
;	                     toPrint += "\n"
;}	                  std::cout << toPrint
;	                        return 0
;}
