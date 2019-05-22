package com.androidapp.wirelesspi;

import android.content.Context;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.VolleyError;
import com.android.volley.toolbox.StringRequest;
import com.android.volley.toolbox.Volley;

public class MainActivity extends AppCompatActivity {

    // create a request queue to handle requests
    RequestQueue queue;



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);



        // set queue to a Volley queue (pre made)
        queue = Volley.newRequestQueue(this);
        /*
        // on click listener
        Button start = findViewById(R.id.btnStart);
        start.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // sends request through url
                StringRequest sReq = new StringRequest(Request.Method.GET, "http://10.145.157.157:9001/drive", new Response.Listener<String>() {
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
            }
        });*/

    }



}
