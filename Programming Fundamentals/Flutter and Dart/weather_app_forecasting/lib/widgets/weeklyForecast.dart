import 'package:flutter/material.dart';

class WeeklyForecast extends StatelessWidget {
  final List<String> _daysOfWeek = [
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday",
    "Sunday",
    "Monday",
    "Tuesday"
  ];

  @override
  Widget build(BuildContext context) {
    return ListView.builder(
      itemCount: _daysOfWeek.length,
      itemBuilder: (context, index) {
        return ListTile(
            title: Row(
          mainAxisAlignment: MainAxisAlignment.spaceBetween,
          children: <Widget>[
            SizedBox(
                width: 120,
                child: Text(_daysOfWeek[index],
                    style: TextStyle(color: Colors.white, fontSize: 22))),
            Text(
              "☁️",
              style: TextStyle(fontSize: 24),
              textAlign: TextAlign.center,
            ),
            Wrap(
              spacing: 20,
              children: <Widget>[
                Text("77", style: TextStyle(fontSize: 24, color: Colors.white)),
                Text("62",
                    style: TextStyle(fontSize: 24, color: Colors.grey[400]))
              ],
            )
          ],
        ));
      },
    );
  }
}
