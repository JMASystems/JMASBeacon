Pod::Spec.new do |s|
  s.name         = "JMASBeacon"
  s.version      = "1.0.0"
  s.summary      = "Beacon Ranging And Monitoring, Sending Library"

  s.homepage     = "http://jmas.co.jp"

  s.author             = { "Akira Hayakawa" => "Akira_Hayakawa@jmas.co.jp" }
  
  s.license      = {
    :type => 'Copyright',
    :text => <<-LICENSE
      Copyright 2014 JMA Systems Corp., All Rights Reserved.
      LICENSE
  }

  s.author       = { "Akira Hayakawa" => "Akira_Hayakawa@jmas.co.jp" }
  s.platform     = :ios, "7.0"

  # 以下、s.sourceはまだ なお上のバージョンとタグは揃えること
  s.source       = { :git => "https://github.com/JMASystems/JMASBeacon.git", :tag => "1.0.0" }
  s.public_header_files = "BeacappSDKforiOS/Header/*.h"

  s.preserve_paths = "JMASBeacon/staticLib/libJMASBeacon.a"
  s.vendored_libraries = "JMASBeacon/staticLib/libJMASBeacon.a"

  s.frameworks = "CoreLocation", "CoreBluetooth"
  s.library   = "JMASBeacon"
  
  s.requires_arc = true
  s.xcconfig =  { 'LIBRARY_SEARCH_PATHS' => '"$(PODS_ROOT)/JMASBeacon/staticLib"','HEADER_SEARCH_PATHS' => '"${PODS_ROOT}/JMASBeacon/Header"' }

end
