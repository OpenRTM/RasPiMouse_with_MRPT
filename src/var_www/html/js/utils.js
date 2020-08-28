/*

*/
function check_ns(){
  $.ajax({ url:"/cgi-bin/check_ns.py" })
      .done(function(data1,textStatus,jqXHR) {
         $("#ns_state").text(data1);
         }
      );
}

function start_ns(){
  location.replace("/cgi-bin/naming.py");
}

function rtsys_cmd(name, cmd){
  //var el = document.getElementById("display_ip");
  //var disp = el.value;

  //location.replace("/cgi-bin/"+name+".py?cmd="+cmd+"&disp="+disp);
  location.replace("/cgi-bin/"+name+".py?cmd="+cmd);
}

function rtclist(){
  $.ajax({ url:"/cgi-bin/rtclist.py" })
      .done(function(data1,textStatus,jqXHR) {
         $("#rtclist").html('<pre>'+data1+'</pre>');
         }
      );
}

