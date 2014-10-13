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
    }
}
