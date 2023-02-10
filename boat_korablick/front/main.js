async function start_weather() {

  

    await eel.ustroistvo()();
    document.getElementById("weather").src = "weather.txt";


}
async function stop_weather(){
    await eel.stop_weather()();
    location.reload();
    document.getElementById("weather").src = "weather.txt";
}


async function start_davl() {
    await eel.davler()();
    document.getElementById("davl").src = "davl.txt";


}

async function stop_davl() {
    await eel.stop_davler()();
    location.reload();
    document.getElementById("davl").src = "davl.txt";

}




async function start_veter() {
    await eel.temper()();
   
    document.getElementById("veter").src = "veter.txt";

}

async function stop_veter() {
    await eel.stop_veter()();
    location.reload();
}

