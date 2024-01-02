package simu5g.simulations.NR.DNPW;

import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;
import inet.networklayer.ipv4.RoutingTableRecorder;
import inet.node.inet.AdhocHost;
import inet.node.inet.Router;
import inet.node.inet.StandardHost;
import inet.node.ethernet.Eth10G;

import simu5g.world.radio.LteChannelControl;
import simu5g.common.carrierAggregation.CarrierAggregation;
import simu5g.nodes.Upf;
import simu5g.common.binder.Binder;
import simu5g.nodes.NR.gNodeB;
import simu5g.nodes.cars.NRCar;
import simu5g.nodes.jammers.NRJammer;

import org.car2x.veins.subprojects.veins_inet.VeinsInetManager;

import inet.visualizer*.common.IntegratedVisualizer;
import org.car2x.veins.visualizer.roads.RoadsCanvasVisualizer;

network Highway
{
    parameters:
        double playgroundSizeX @unit(m); // x size of the area the nodes are in (in meters)
        double playgroundSizeY @unit(m); // y size of the area the nodes are in (in meters)
        double playgroundSizeZ @unit(m); // z size of the area the nodes are in (in meters)
        @display("bgb=580,470");

    submodules:

        routingRecorder: RoutingTableRecorder {
            @display("p=500,75;is=s");
        }
        configurator: Ipv4NetworkConfigurator {
            @display("p=500,125");
            config = xmldoc("demo.xml");
        }

        //# Veins manager module
        veinsManager: VeinsInetManager {
            @display("p=500,227;is=s");
        }
        visualizer: IntegratedVisualizer {
            @display("p=500,350");
        }

        //# LTE modules
        channelControl: LteChannelControl {
            @display("p=500,25;is=s");
        }
        binder: Binder {
            @display("p=500,175;is=s");
        }
        carrierAggregation: CarrierAggregation {
            @display("p=500,275;is=s");
        }
        roadsCanvasVisualizer: RoadsCanvasVisualizer {
            @display("p=500,415");
        }
        jammer: NRJammer {
            @display("p=200,8;is=vs");
        }
        //# submodule vector to store all cars - will be filled dynamically during simulations
        car[0]: NRCar;
}

