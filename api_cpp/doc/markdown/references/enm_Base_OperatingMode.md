# Enum OperatingMode

This page describes the C++ Kinova::Api::Base::OperatingMode enumeration.

## Overview / Purpose

List of admissible robot operating modes \(used to report robot firmware upgrade current state\)

## Enumeration definition

|Enumerator|Value|Description|
|----------|-----|-----------|
|UNSPECIFIED\_OPERATING\_MODE|0|Unspecified operating mode|
|MAINTENANCE\_MODE|1|Robot in maintenance mode|
|UPDATE\_MODE|2|Robot waiting for upgrade package|
|UPDATE\_COMPLETED\_MODE|3|Robot update successfully completed|
|UPDATE\_FAILED\_MODE|4|Robot update failed|
|SHUTTING\_DOWN\_MODE|5|Robot about to shutdown|
|RUN\_MODE|6|Robot properly running \(or normal operation mode\)|
|UPDATING\_DEVICE\_MODE|7|Robot updating device|

**Parent topic:** [Base](../references/summary_Base.md)

