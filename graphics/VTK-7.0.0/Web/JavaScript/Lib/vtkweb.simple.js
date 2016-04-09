/**
 * vtkWeb JavaScript Library.
 *
 * This module provide simpler connection paradigm for the Web client
 * to connect to a remote vtkWeb session.
 *
 * This module registers itself as: 'vtkweb-simple'
 *
 * @class vtkWeb.simple
 */
(function (GLOBAL, $) {

    // Connections field used to store a map of the active sessions
    var module = {};

    function autoConnect(connection, ready, close) {
        if(connection.hasOwnProperty('sessionURL')) {
            // Direct connect
            vtkWeb.connect(connection, ready, close);
        } else {
            // Launch process
            vtkWeb.start( connection, function(connection) {
                if(connection.error) {
                    alert(connection.error);
                    close("error", connection.error);
                } else {
                    // The process successfuly started
                    // => Just connect to the WebSocket
                    vtkWeb.connect(connection, ready, close);
                }
            }, function(msg) {
                // No launcher found or error
                try {
                  var launcherResponse = JSON.parse(msg.responseText);
                  close("launcher error", launcherResponse);
                } catch (err) {
                  console.log("No launcher found.  Attempting to connect using the direct WS url.");
                  connection.sessionURL = vtkWeb.properties.sessionURL;
                  vtkWeb.connect(connection, ready, close);
                }
            });
        }
    }

    // ----------------------------------------------------------------------
    // Init vtkWeb module if needed
    // ----------------------------------------------------------------------
    if (GLOBAL.hasOwnProperty("vtkWeb")) {
        module = GLOBAL.vtkWeb || {};
    } else {
        GLOBAL.vtkWeb = module;
    }

    // ----------------------------------------------------------------------
    // Export methods to the vtkWeb module
    // ----------------------------------------------------------------------

    /**
     * Simple method that will automatically try to launch or connect
     * to an existing session based on URL parameters and failures.
     *
     * @member vtkWeb.simple
     * @method smartConnect
     *
     * @param {Object} base connection information
     * @param {Function} callback when success which expect
     *                   a full connection object as argument.
     * @param {Function} callback when failure occurs with "code" and "reason"
     *                   why the failure occured.
     */
    module.smartConnect = function (connection, ready, close) {
        if(close === undefined) {
            close = module.errorCallback;
        }
        // Extend connection with URL parameters
        module.udpateConnectionFromURL(connection);

        // Check if we should connect to an existing session
        if(connection.hasOwnProperty('session')) {
            var url = connection['sessionManagerURL'] + connection['session'];
            $.ajax({
              url: url,
              dataType: 'json'
            }).done(function(realConnection){
                autoConnect(realConnection, ready, close);
            }).fail(function(arg){
                alert("Unable to connect to the given session: " + connection['session']);
                close("error", "Unable to connect to the given session: " + connection['session']);
            });
        } else {
            autoConnect(connection, ready, close);
        }
    };

    // ----------------------------------------------------------------------
    // Local module registration
    // ----------------------------------------------------------------------
    try {
      // Tests for presence of autobahn, then registers this module
      if (module.allModulesPresent(['vtkweb-connect', 'vtkweb-launcher'])) {
        module.registerModule('vtkweb-simple');
      } else {
        console.error('Module failed to register, vtkweb-connect and vtkweb-launcher are missing');
      }
    } catch(err) {
      console.error('Caught exception while registering module: ' + err.message);
    }

}(window, jQuery));
