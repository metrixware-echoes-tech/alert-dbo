# Private class
class echoes_alert_dbo::install inherits echoes_alert_dbo {
  if $caller_module_name != $module_name {
    fail("Use of private class ${name} by ${caller_module_name}")
  }

  package { 'libpq5':
    ensure => 'present',
    tag    => 'postgresql',
  }

  file { '/usr/local/lib/libdbo.so':
    ensure => 'file',
    owner  => 0,
    group  => 'staff',
    mode   => '0755',
    source => "puppet:///modules/${module_name}/${echoes_alert_dbo::branch}/${echoes_alert_dbo::version}/libdbo.so",
  }->
  exec { "ldconfig_${module_name}":
    path        => [ '/bin', '/sbin', '/usr/bin', '/usr/sbin' ],
    refreshonly => true,
    subscribe   => File['/usr/local/lib'],
  }
}
