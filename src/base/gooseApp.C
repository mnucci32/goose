#include "gooseApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<gooseApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

gooseApp::gooseApp(InputParameters parameters) : MooseApp(parameters)
{
  gooseApp::registerAll(_factory, _action_factory, _syntax);
}

gooseApp::~gooseApp() {}

void
gooseApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"gooseApp"});
  Registry::registerActionsTo(af, {"gooseApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
gooseApp::registerApps()
{
  registerApp(gooseApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
gooseApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  gooseApp::registerAll(f, af, s);
}
extern "C" void
gooseApp__registerApps()
{
  gooseApp::registerApps();
}
