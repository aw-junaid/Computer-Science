import 'package:flutter/material.dart';
import 'package:weather/widgets/hourlyForecast.dart';
import 'package:weather/widgets/weeklyForecast.dart';

class HomePage extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
        body: Container(
          decoration: BoxDecoration(
            gradient: LinearGradient(
              colors: [
                Colors.blue[100], 
                Colors.blue[800]
              ]
            )
          ),
          child: CustomScrollView(
          slivers: <Widget>[
            SliverAppBar(
              backgroundColor: Colors.transparent,
              bottom: PreferredSize(preferredSize: Size(100, 100), child: Column(
                children: <Widget>[
                  Text("Partly Cloudy",style: TextStyle(fontSize: 20, color: Colors.white)),
                  Text("55",style: TextStyle(fontSize: 50, color: Colors.white))
                ],
              )),
              expandedHeight: 200,
              pinned: true,
              flexibleSpace: FlexibleSpaceBar(
                  titlePadding: EdgeInsets.all(50),
                  title: Padding(
                    padding: const EdgeInsets.only(bottom: 50.0),
                    child: Text("Houston",style: TextStyle(fontSize: 30, fontWeight: FontWeight.w300)),
                  ) ,
              ),
            ),
            SliverList(
              delegate: SliverChildListDelegate([
                Divider(color: Colors.grey[800]),
                Container(
                  height: 100, 
                  width: double.infinity,
                  child: HourlyForecast()
                  ),
                Divider(color: Colors.grey[800]), 
                Container(
                  height: MediaQuery.of(context).size.height,
                  child: WeeklyForecast()) 
              ]),
            ) 
            
          ],
            ),
        )
      );
  }
}
