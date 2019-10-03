#include <iostream>
using namespace std;

#include "models.h"
#include "database.h"
Reviews reviews;
// Categorys categors;
// Hashtags hashtags;
// Descriptions descriptions;
// Posts posts;

#include "views.h"
#include "modules.h"
#include "controllers.h"
Controllers controllers;
int main()
{
    controllers.initialize();
    return 0;
}