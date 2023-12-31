//
//                  Simu5G
//
// Authors: Giovanni Nardini, Giovanni Stea, Antonio Virdis (University of Pisa)
//
// This file is part of a software released under the license included in file
// "license.pdf". Please read LICENSE and README files before using it.
// The above files and the present reference are part of the software itself,
// and cannot be removed from it.
//

#include "apps/alert/AlertReceiver.h"
#include <inet/common/ModuleAccess.h>  // for multicast support

Define_Module(AlertReceiver);
using namespace inet;

void AlertReceiver::initialize(int stage)
{
    cSimpleModule::initialize(stage);

    if (stage != inet::INITSTAGE_APPLICATION_LAYER)
        return;

    int port = par("localPort");
    EV << "AlertReceiver::initialize - binding to port: local:" << port << endl;
    if (port != -1)
    {
        socket.setOutputGate(gate("socketOut"));
        socket.bind(port);

        // for multicast support
        inet::IInterfaceTable *ift = inet::getModuleFromPar<inet::IInterfaceTable>(par("interfaceTableModule"), this);
        inet::MulticastGroupList mgl = ift->collectMulticastGroups();
        socket.joinLocalMulticastGroups(mgl);

        // if the multicastInterface parameter is not empty, set the interface explicitly
        const char *multicastInterface = par("multicastInterface");
        if (multicastInterface[0]) {
            NetworkInterface *ie = ift->findInterfaceByName(multicastInterface);
            if (!ie)
                throw cRuntimeError("Wrong multicastInterface setting: no interface named \"%s\"", multicastInterface);
            socket.setMulticastOutputInterface(ie->getInterfaceId());
        }

        // -------------------- //
    }

    alertDelay_ = registerSignal("alertDelay");
    alertRcvdMsg_ = registerSignal("alertRcvdMsg");

    nrReceived = 0;
    delaySum = 0;
}

void AlertReceiver::handleMessage(cMessage *msg)
{
    if (msg->isSelfMessage())
        return;

    Packet* pPacket = check_and_cast<Packet*>(msg); // parser

    // read Alert header
    auto alert = pPacket->popAtFront<AlertPacket>();

    //export
    int port = par("localPort");
    if(port == 1000){
        std::ofstream outputFile("out_msgReceived1000.txt", std::ios::app);
        if(outputFile.is_open()){
            outputFile << alert->getPayloadTimestamp() << "," << port << endl;
            outputFile.close();
        }
    }else{
        std::ofstream outputFile("out_msgReceived1001.txt", std::ios::app);
        if(outputFile.is_open()){
            outputFile << alert->getPayloadTimestamp() << "," << port << endl;
            outputFile.close();
        }
    }

    // emit statistics
    simtime_t delay = simTime() - alert->getPayloadTimestamp();
    emit(alertDelay_, delay);
    emit(alertRcvdMsg_, (long)1);
    nrReceived++;
    delaySum+=delay;

    EV << "AlertReceiver::handleMessage - Packet received: SeqNo[" << alert->getSno() << "] Delay[" << delay << "]" << endl;

    delete msg;
}

void AlertReceiver::refreshDisplay() const
{
    char buf[80];
    if(nrReceived >0){
        sprintf(buf, "received: %ld pks\nav. delay: %s s", nrReceived, (delaySum/nrReceived).format(-4).c_str());
    } else {
        sprintf(buf, "received: 0 pks");
    }
    getDisplayString().setTagArg("t", 0, buf);
}

