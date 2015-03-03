/*
 * Jlibfprint
 * Copyright (C) 2012 Fabio Scippacercola <nonplay.programmer@gmail.com>
 *                    Agostino Savignano <savag88@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */
package jlibfprint;

import java.util.Arrays;

/**
 *  A simple execution can be used to test the library.
 * @author agostino
 */
public class SampleRun {
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        DiscoveredDeviceList discoveredDeviceList = JlibFprint.discoverDevices();
        listDiscoveredDevices(discoveredDeviceList);
        DiscoveredDevice firstDiscoveredDevice = getFirstDiscoveredDevice(discoveredDeviceList);

        if (firstDiscoveredDevice == null) {
            System.out.println("No device found to enroll fingers");
        } else {
            Device device = firstDiscoveredDevice.open();
            showDeviceInfo(device);
            EnrollResult enrollResult = enroll(device);
            if (EnrollResultCode.COMPLETE.equals(enrollResult.getCode())) {
                System.out.println("Print data: " + Arrays.toString(enrollResult.getPrintData().getData())); //print data get's set now only.
                identify(device, enrollResult.getPrintData());
            }
            device.close();
        }

    }

    private static void showDeviceInfo(Device device) {
        System.out.println("=====================================");
        System.out.println("Device: " + device);
        System.out.println("\tNumber of enroll stages: " + device.getNumberEnrollStages());
        System.out.println("\tImage width: " + device.getImageWidth());
        System.out.println("\tImage height: " + device.getImageHeight());
        System.out.println("=====================================");
    }

    private static void listDiscoveredDevices(DiscoveredDeviceList discoveredDeviceList) {
        System.out.println("Devices discovered: " + discoveredDeviceList.getDiscoveredDevices().length);
        for(DiscoveredDevice discoveredDevice: discoveredDeviceList.getDiscoveredDevices()) {
            System.out.println("=====================================");
            System.out.println(discoveredDevice);
            System.out.println("\ttype_id: " + discoveredDevice.getType());
            System.out.println("\tdriver_id: " + discoveredDevice.getDriverId());
            System.out.println("\tDriver.name: " + discoveredDevice.getDriver().getName());
            System.out.println("\tDriver.full_name: " + discoveredDevice.getDriver().getFullName());
            System.out.println("\tDriver.id: " + discoveredDevice.getDriver().getId());
        }
        System.out.println("=====================================");
    }

    private static DiscoveredDevice getFirstDiscoveredDevice(DiscoveredDeviceList discoveredDeviceList) {
        return discoveredDeviceList.getDiscoveredDevices().length > 0
                ? discoveredDeviceList.getDiscoveredDevices()[0]
                : null;
    }

    private static EnrollResult enroll(Device device) {
        EnrollResult enrollResult = null;
        for ( int i = 0 ; i < device.getNumberEnrollStages() ; i++ ) {
            System.out.println("Please, enroll the finger");
            enrollResult = device.enroll();
            System.out.println("Enroll result code: " + enrollResult.getCode());
        }
        return enrollResult;
    }

    private static void identify(Device device, PrintData printData) {
        System.out.println("Please, enroll the finger again to verify");
        VerifyResultCode result = device.verify(printData);
        System.out.println("Verify result code: " + result);        
    }

}
