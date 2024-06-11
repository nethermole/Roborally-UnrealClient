# Roborally-UnrealClient
Unreal Engine 5 client, used to visualize game in roborally repo

Functional Summary:

On main menu load, create MainMenu widget
When play button clicked, gameInstance parameters set, and load Board level
Board level blueprint gets the BoardDrawerObject and calls drawboard
Drawboard makes the rest call, callbacking to add the tile gameobjects to the world