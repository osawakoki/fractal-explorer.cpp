#include "pugixml.hpp"
#include <iostream>
#include <string>

#include "config.hpp"
#include "commandline_parser.hpp"
#include "print_config.hpp"
#include "hsl_to_rgb.hpp"

#include "drawer.mandelbrot.hpp"
#include "drawer.julia.hpp"
#include "drawer.tricorn.hpp"

int main() {

  Config* config_ptr = commandline_parser();
  Config config = *config_ptr;

  delete config_ptr;

  print_config(config);

  mandelbrot_drawer(*config.mandelbrot);
  delete config.mandelbrot;

  julia_drawer(*config.julia);
  delete config.julia;

  tricorn_drawer(*config.tricorn);
  delete config.tricorn;

  return 0;
}
