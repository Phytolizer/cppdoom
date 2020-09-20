//
// Created by kyle on 9/20/20.
//

#include "doom_main.hh"

#include "deh.hh"

void doom::main()
{
  doom::mainSetup();
}

void doom::mainSetup()
{
  deh::buildBexTables();
}
