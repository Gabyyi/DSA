#include <iostream>
#include "ImgSegm.hpp"

int main() {

    ImageSegm imageSegm("input.txt", "output.txt");
    imageSegm.process();
    return 0;
}
