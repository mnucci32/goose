//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "gooseTestApp.h"
#include "gooseApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<gooseTestApp>()
{
  InputParameters params = validParams<gooseApp>();
  return params;
}

gooseTestApp::gooseTestApp(InputParameters parameters) : MooseApp(parameters)
{
  gooseTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

gooseTestApp::~gooseTestApp() {}

void
gooseTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  gooseApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"gooseTestApp"});
    Registry::registerActionsTo(af, {"gooseTestApp"});
  }
}

void
gooseTestApp::registerApps()
{
  registerApp(gooseApp);
  registerApp(gooseTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
gooseTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  gooseTestApp::registerAll(f, af, s);
}
extern "C" void
gooseTestApp__registerApps()
{
  gooseTestApp::registerApps();
}
