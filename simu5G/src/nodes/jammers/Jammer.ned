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


package simu5g.nodes.jammers;

import inet.applications.contract.IApp;
import inet.mobility.contract.IMobility;
import inet.networklayer.common.InterfaceTable;
import inet.networklayer.contract.IRoutingTable;
import inet.networklayer.contract.INetworkLayer;
import inet.networklayer.configurator.ipv4.HostAutoConfigurator;
import inet.transportlayer.tcp.Tcp;
import inet.transportlayer.udp.Udp;
import inet.common.MessageDispatcher;

import simu5g.nodes.NR.NRJammer;
import simu5g.nodes.jammerNode;

import org.car2x.veins.base.modules.*;

// 
// Car Module
//
module Jammer extends jammerNode
{
    parameters:

        @display("i=device/drone");

        //# Mobility
        //mobility.typename = default("VeinsInetMobility");
}


// 
// Car Module
//
module NRJammer extends NRJammer
{
    parameters:

        @display("i=device/drone");

        //# Mobility
        //mobility.typename = default("VeinsInetMobility");
}