class echoes_alert_dbo (
  $branch  = $echoes_alert_dbo::params::branch,
  $version = $echoes_alert_dbo::params::version
) inherits echoes_alert_dbo::params {
  validate_string($branch)
  validate_string($version)

  require wt
 
  anchor { "${module_name}::begin": } ->
  class { "${module_name}::install": } ->
  anchor { "${module_name}::end": }
}
