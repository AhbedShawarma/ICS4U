package com.androidapp.twittertutorial;

import android.content.Context;
import android.os.Bundle;
import android.support.annotation.NonNull;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import com.twitter.sdk.android.tweetui.TweetTimelineRecyclerViewAdapter;
import com.twitter.sdk.android.tweetui.UserTimeline;

public class TimelineFragment extends Fragment {
    private Context context;
    private RecyclerView recyclerView;
    private TweetTimelineRecyclerViewAdapter adapter;

    @Override
    public void onAttach(Context context) {
        super.onAttach(context);
        this.context = context;
    }

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        return inflater.inflate(R.layout.timeline_fragment, container, false);
    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        // when created, calls the recycler view (list) and loads the timeline
        super.onViewCreated(view, savedInstanceState);
        setUpRecyclerView(view);
        loadUserTimeline();
    }

    private void setUpRecyclerView(@NonNull View view) {
        recyclerView = view.findViewById(R.id.user_timeline_recycler_view);
        LinearLayoutManager linearLayoutManager = new LinearLayoutManager(context);
        recyclerView.setLayoutManager(linearLayoutManager);
    }

    private void loadUserTimeline() {
        UserTimeline userTimeline = new UserTimeline.Builder()
                .screenName("Play2ChangeWMT")
                .maxItemsPerRequest(50)
                .build();

        adapter = new TweetTimelineRecyclerViewAdapter.Builder(context)
                .setTimeline(userTimeline)
                .setViewStyle(R.style.tw__TweetLightStyle)
                .build();

        recyclerView.setAdapter(adapter);
    }

}
