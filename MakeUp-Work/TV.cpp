int main() {
    TV myTV;
    myTV.SetStation(9);
    myTV.displayStatus();

    myTV.SetStation(10);
    myTV.displayStatus();

    TV myOtherTV(2);
    myOtherTV.displayStatus();

    return 0;
}