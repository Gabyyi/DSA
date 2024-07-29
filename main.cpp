#include <iostream>
#include <stdlib.h>
#include "hash.h"
#include <iostream>
#define VMAX 17
#define P 13

using namespace std;

//hash function defined by us
int hfunc(string key) {
    int hkey = 0;
    for (int i = 0; i < key.length(); i++)
        hkey = (hkey * P + key[i]) % VMAX;
    return hkey;
}

Hashtable<string, double> hid(VMAX, hfunc);

int main() {

    hid.put("RR327123", 7.9);
    hid.put("RK227543", 8.3);
    hid.put("JK432871", 2.5);
    cout<< "Value of a certain key (RK227543): " << hid.get("RK227543");


	return 0;
}

