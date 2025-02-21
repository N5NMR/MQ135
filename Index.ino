void checkAirQuality(int air_quality) 
{
    if (air_quality <= 50) 
    {
        air_Index = "Gut";
    } 
    else if (air_quality <= 100) 
    {
        air_Index = "OK";
    } 
    else if (air_quality <= 150) 
    {
        air_Index = "Nicht ok";
    } 
    else if (air_quality <= 200) 
    {
        air_Index = "Ungesund";
    } 
    else if (air_quality <= 300) 
    {
        air_Index = "Sehr ungesund";
    } 
    else 
    {
        air_Index = "Gefährlich";
    }
}