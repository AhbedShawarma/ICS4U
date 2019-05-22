package com.androidapp.wirelesspi;

import android.app.Activity;
import android.content.Context;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.os.Bundle;
import android.widget.TextView;

public class TiltSensor extends Activity implements SensorEventListener {

    // defining variables for sensor
    private SensorManager sensorManager;
    private Sensor sensor;
    private TextView textView;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activitysensor);

        //declaring Sensor Manager and sensor type
        sensorManager = (SensorManager)getSystemService(Context.SENSOR_SERVICE);
        sensor = sensorManager.getDefaultSensor(Sensor.TYPE_ACCELEROMETER);

        textView = (TextView)findViewById(R.id.tiltText);
    }

    @Override
    public void onAccuracyChanged(Sensor arg0, int arg1) {
    }

    @Override
    public void onSensorChanged(SensorEvent event) {
        float x = event.values[0];
        float y = event.values[1];

        textView.setText(Float.toString(y));

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
