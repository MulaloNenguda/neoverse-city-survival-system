#include "CityComponent.h"

CityComponent::CityComponent(string name)
{
    componentName = name;
}

string CityComponent::getComponentName()
{
    return componentName;
}

CityComponent::~CityComponent()
{
}