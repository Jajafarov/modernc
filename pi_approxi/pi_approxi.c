#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <assert.h>

unsigned long factorial(int a){
    assert(a >= 0);
    
    unsigned long x = 1;

    for(unsigned long i = 1; i <= a; i++){
	x *= i;
    }

    return x;
}


int main(int argc, char* argv[argc+1]){
    int dig = atoi(argv[1]);
    int p = 1 + (dig/8);
    mpf_t pi_inv, numer, denom1, denom2, terms;
    /* mpz_t fact; */

    mpf_init(pi_inv);
    mpf_init(numer);
    mpf_init(denom1);
    mpf_init(denom2);
    mpf_init(terms);
    mpf_set_ui(terms, 0);
    /* mpz_init(fact); */

    mpf_sqrt_ui(pi_inv, 8);
    mpf_div_ui(pi_inv, pi_inv, 9801);


    for(int i = 0; i <= p; i++){
	mpf_set_ui(numer, 26390);
	mpf_mul_ui(numer, numer, i);
	mpf_add_ui(numer, numer, 1103);
	mpf_mul_ui(numer, numer, factorial(4*i));

	mpf_set_ui(denom1, factorial(i));
	mpf_pow_ui(denom1, denom1, 4);

	mpf_set_ui(denom2, 396);
	mpf_pow_ui(denom2, denom2, 4*i);

	mpf_mul(denom1, denom1, denom2);
	mpf_div(numer, numer, denom1);

	mpf_add(terms, terms, numer);
    }

    mpf_mul(pi_inv, pi_inv, terms);
    mpf_ui_div(pi_inv, 1, pi_inv);

    mpf_out_str(stdout, 1, dig, pi_inv);
    puts("");

    mpf_clear(pi_inv);
    mpf_clear(numer);
    mpf_clear(denom1);
    mpf_clear(denom2);
    mpf_clear(terms);
    return 0;    
}
