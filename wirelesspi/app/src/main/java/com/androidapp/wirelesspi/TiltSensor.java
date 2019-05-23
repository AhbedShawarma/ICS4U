package com.androidapp.wirelesspi;

import android.app.Activity;
import android.content.Context;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.VolleyError;
import com.android.volley.toolbox.StringRequest;
import com.android.volley.toolbox.Volley;

public class TiltSensor extends Activity implements SensorEventListener {
    // IP ADDRESS 10.145.158.158
    // defining variables for sensor
    private SensorManager sensorManager;
    private Sensor sensor;
    private TextView textView;

    // create a request queue to handle requests
    RequestQueue queue;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activitysensor);

        //declaring Sensor Manager and sensor type
        sensorManager = (SensorManager)getSystemService(Context.SENSOR_SERVICE);
        sensor = sensorManager.getDefaultSensor(Sensor.TYPE_ACCELEROMETER);

        // set queue to a Volley queue (pre made)
        queue = Volley.newRequestQueue(this);

        textView = (TextView)findViewById(R.id.tiltText);
    }

    @Override
    public void onAccuracyChanged(Sensor arg0, int arg1) {
    }

    @Override
    public void onSensorChanged(SensorEvent event) {
        //float x = event.values[0];

        /*REQUIREMENTS:
            200 step motor
            0 = 25
            5 = 50
         */
        float y = event.values[1];

        if (y < -5)
            y = -5;
        if (y > 5)
            y = 5;
        float steps = (y*5) + 25;
        textView.setText(Float.toString(Math.round(steps)));

        // sends request through url
        StringRequest sReq = new StringRequest(Request.Method.GET, "http://10.145.158.158/turn?angle=" + textView.getText() , new Response.Listener<String>() {
            @Override
            public void onResponse(String response) {
                Log.d("yeet", response);
            }
        }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError error) {
                Log.d("s", "ss");
            }
        });

        queue.add(sReq);

        //if (Math.abs(x) > Math.abs(y)) {

/*
        //if (Math.abs(x) > Math.abs(y)) {
        if (x < 0)
            textView.setText("TILT RIGHT");
        if (x > 0)
            textView.setText("TILT LEFT");
        }
        else {
            if (y < 0)
                textView.setText("You tilt the device up");
            if (y > 0)
                textView.setText("You tilt the device down");
        }
        if (x > (-2) && x < (2) && y > (-2) && y < (2))
            textView.setText("Not tilt device");
*/
    }

    @Override
    protected void onResume() {
        super.onResume();
        sensorManager.registerListener(this, sensor, SensorManager.SENSOR_DELAY_NORMAL);
    }

    @Override
    protected void onPause() {
        super.onPause();
        //unregister Sensor listener
        sensorManager.unregisterListener(this);
    }
}
