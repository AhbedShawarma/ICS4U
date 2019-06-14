package com.androidapp.twittertutorial;


import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;


import com.twitter.sdk.android.core.DefaultLogger;
import com.twitter.sdk.android.core.Twitter;
import com.twitter.sdk.android.core.TwitterAuthConfig;
import com.twitter.sdk.android.core.TwitterConfig;

public class MainActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        TwitterConfig config = new TwitterConfig.Builder(this)
                .logger(new DefaultLogger(Log.DEBUG))
                .twitterAuthConfig(new TwitterAuthConfig("3nVuSoBZnx6U4vzUxf5w", "Bcs59EFbbsdF6Sl9Ng71smgStWEGwXXKSjYvPVt7qys"))
                .debug(true)
                .build();
        Twitter.initialize(config);

        if (savedInstanceState == null) {
            getSupportFragmentManager().beginTransaction().replace(R.id.fragment_container, new TimelineFragment()).commit();
        }
    }
}
