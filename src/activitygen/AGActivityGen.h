/****************************************************************************/
// Eclipse SUMO, Simulation of Urban MObility; see https://eclipse.dev/sumo
// Copyright (C) 2010-2025 German Aerospace Center (DLR) and others.
// activitygen module
// Copyright 2010 TUM (Technische Universitaet Muenchen, http://www.tum.de/)
// This program and the accompanying materials are made available under the
// terms of the Eclipse Public License 2.0 which is available at
// https://www.eclipse.org/legal/epl-2.0/
// This Source Code may also be made available under the following Secondary
// Licenses when the conditions for such availability set forth in the Eclipse
// Public License 2.0 are satisfied: GNU General Public License, version 2
// or later which is available at
// https://www.gnu.org/licenses/old-licenses/gpl-2.0-standalone.html
// SPDX-License-Identifier: EPL-2.0 OR GPL-2.0-or-later
/****************************************************************************/
/// @file    AGActivityGen.h
/// @author  Piotr Woznica
/// @author  Daniel Krajzewicz
/// @author  Walter Bamberger
/// @author  Michael Behrisch
/// @date    July 2010
///
// Main class that handles City, Activities and Trips
/****************************************************************************/
#pragma once
#include <config.h>

#include "city/AGCity.h"


// ===========================================================================
// class declarations
// ===========================================================================
class OutputDevice;
class RONet;
class AGTrip;


// ===========================================================================
// class definitions
// ===========================================================================
/**
 * @class AGActivityGen
 * @brief Central object handling City, Activities and Trips
 */
class AGActivityGen {
public:
    //AGActivityGen() {};
    /** @brief Constructor
     *
     * @param[in] input input stat-file name (containing information about the city)
     * @param[in] output xml file in which we'll write the routes generated
     * @param[in] net network of the city
     */
    AGActivityGen(std::string input, OutputDevice& output, RONet* net) :
        inputFile(input),
        outputFile(output),
        net(net),
        //activities(),
        city(net) {};
    /** @brief build the internal city
     *
     * TO CALL 1: First function to be called:
     * imports the XML input file and generates the whole city.
     */
    void importInfoCity();

    /**@brief build activities and trips of the population and generate routes
     *
     * TO CALL 2:
     * generates City's Activity and the corresponding trips
     *
     * @param[in] days      : duration of the simulation (>=0) (day of the end - day of the beginning)
     * @param[in] beginTime : instant of the simulation beginning (in the first day)
     * @param[in] endTime   : instant of the simulation ending (in the last day)
     * NOTE: if (days==0) : endTime > beginTime
     *
     * EXAMPLE: if days=1, endTime=0, beginTime=0: The duration
     * will be 24 hours from 12am to 12amof the next day
     */
    void makeActivityTrips(int days = 1, int beginTime = 0, int endTime = 0);

protected:
    // @brief xml file statistics on the city and generated routes
    std::string inputFile;
    /// @brief The generated routes
    OutputDevice& outputFile;
    // @brief network of the city
    RONet* net;
    //Activities activities;
    // @brief city object containing all households and vehicles
    AGCity city;
    // @brief time of beginning and ending of the simulation and the duration of the simulation in days (min 1 day (beginning and end in the same day)
    int durationInDays, beginTime, endTime;

    /**
     * @brief validation: compatibility of the given trip
     *
     * @param[in] trip to be validated
     *
     * @returns whether the trip is compatible with the time boundaries or not.
     * for this begin, end and duration of the simulation must be defined
     */
    bool timeTripValidation(const AGTrip& trip) const;
    /**
     * @brief generate the output file (trips or routes) using a trip list
     *
     * @param[in] trips generated by the different activities
     */
    void generateOutputFile(std::list<AGTrip>& trips);
    /**
     * @breif introduce a slight variation into the departure time of "default" vehicles
     *
     * @param[in] trip on which a random (normally distributed) variation will be tried
     */
    void varDepTime(AGTrip& trip) const;

private:
    /// @brief invalidated assignment operator
    AGActivityGen& operator=(const AGActivityGen&);
};
