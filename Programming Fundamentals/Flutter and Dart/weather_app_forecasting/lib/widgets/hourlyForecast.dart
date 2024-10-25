
import 'package:flutter/material.dart';

class HourlyForecast extends StatelessWidget {

  var _hours = new List<int>.generate(24, (i) => i + 1);

  @override
  Widget build(BuildContext context) {
    return ListView.builder(
      scrollDirection: Axis.horizontal,
      itemCount: 24,
      itemBuilder: (context, index) {

        final hour = _hours[index]; 

        return Padding(
          padding: const EdgeInsets.all(8.0),
          child: Column(
            children: <Widget>[
              Text("$hour PM",style: TextStyle(color: Colors.white, fontSize: 18)),
              Text("☁️", style: TextStyle(fontSize: 24)),
              Text("${55 + hour}",style: TextStyle(color: Colors.white, fontSize: 18))
            ],
          ),
        );
      },
    );
  }
}