# echoes-alert-dbo

#### Table of Contents

1. [Overview](#overview)
2. [Module Description - What the module does and why it is useful](#module-description)
3. [Setup - The basics of getting started with wt](#setup)
    * [Setup requirements](#setup-requirements)
    * [Beginning with echoes_alert_dbo](#beginning-with-echoes_alert_dbo)
4. [Usage - Configuration options and additional functionality](#usage)
5. [Reference - An under-the-hood peek at what the module is doing and how](#reference)
6. [Limitations - OS compatibility, etc.](#limitations)
7. [Development - Guide for contributing to the module](#development)
8. [Contributors](#contributors)

## Overview

Puppet module to manage Echoes Alert DBO installation and configuration.

## Module Description

This module installs and configures Echoes Alert DBO.

## Setup

### Setup requirements

This module requires Wt to be installed.

You can use [echoes-wt](https://github.com/echoes-tech/puppet-wt) to install Wt.

The DBO resources (binaries, configuration files, etc.) should be located in the `files` or `templates` directories of the module, under the path `/$branch_name/$version_number/`.

### Beginning with echoes_alert_dbo

```puppet
include 'echoes_alert_dbo'
```

## Usage

An example of resource-like class declaration: 

```puppet
class {'echoes_alert_dbo':
  branch  => 'develop',
  version => 'latest',
}
```

## Reference

### Classes

#### Public classes

* echoes_alert_dbo: Main class, includes all other classes.

#### Private classes

* echoes_alert_dbo::params: Sets parameter defaults.
* echoes_alert_dbo::install: Handles the binary.

#### Parameters

The following parameters are available in the `::echoes_alert_dbo` class:

##### `branch`

Tells Puppet which branch to choose to install DBO. Valid options: string. Default value: 'master'

##### `version`

Tells Puppet which version to choose to install DBO. Valid options: 'latest' or a specific version number. Default value: 'latest'

## Limitations

Debian family OSes is officially supported. Tested and built on Debian.

##Development

[Echoes Technologies](https://www.echoes-tech.com) modules on the Puppet Forge are open projects, and community contributions are essential for keeping them great.

## Contributors

The list of contributors can be found at: https://forge.echoes-tech.com/projects/dbo/repository/statistics#statistics-contributors
