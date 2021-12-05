#ifndef CATCH_CONFIG_MAIN
#  define CATCH_CONFIG_MAIN
#endif

#include <catch/catch.hpp>
#include <fork.hpp>

TEST_CASE("constructor, trim, file reading", "[Michael]") {
    Fork test("TestStory.txt");

    std::set<std::string> topleft{"topmid","midleft"};
    std::set<std::string> topmid{"topleft","topright","midmid"};
    std::set<std::string> topright{"topmid","midright"};

    std::set<std::string> midleft{"topleft","midmid","botleft"};
    std::set<std::string> midmid{"topmid","midright","botmid","midleft"};
    std::set<std::string> midright{"topright","midmid","botright"};

    std::set<std::string> botleft{"midleft","botmid"};
    std::set<std::string> botmid{"botright","midmid","botleft"};
    std::set<std::string> botright{"midright","botmid"};

    std::map<std::string, Node<std::string>*> adj_ = test.getAdj_();
    REQUIRE(adj_.size() == 9);

    REQUIRE(adj_.at("topleft") -> actions == topleft);
    REQUIRE(adj_.at("topmid") -> actions == topmid);
    REQUIRE(adj_.at("topright") -> actions == topright);

    REQUIRE(adj_.at("midleft") -> actions == midleft);
    REQUIRE(adj_.at("midmid") -> actions == midmid);
    REQUIRE(adj_.at("midright") -> actions == midright);

    REQUIRE(adj_.at("botleft") -> actions == botleft);
    REQUIRE(adj_.at("botmid") -> actions == botmid);
    REQUIRE(adj_.at("botright") -> actions == botright);
}

TEST_CASE("TEST getter setter", "[Michael]") {
    Fork test("TestStory.txt");
    REQUIRE(test.getNodeInfo() == "Starting Node");
    REQUIRE(test.getStartingAction() == "topleft");
    REQUIRE(test.getCurrentAction() == "topleft");
    REQUIRE(test.getEndingAction() == "botright");

    test.setCurrentAction("topmid");
    REQUIRE(test.getCurrentAction() == "topmid");
    REQUIRE(test.getNodeInfo() == "this is a node");

    std::set<std::string> adj_nodes{"topleft", "topright", "midmid"};
    REQUIRE(test.getCurrentActions() == adj_nodes);

    test.setCurrentAction("botright");
    REQUIRE(test.getNodeInfo() == "End Node");
    adj_nodes = {"botmid", "midright"};
    REQUIRE(test.getCurrentActions() == adj_nodes);
    REQUIRE(test.getCurrentAction() == test.getEndingAction());
}

TEST_CASE("BFS (semi-complex-story.txt)", "[Michael]") {
    Fork test("semi-complex-story.txt");
    REQUIRE(test.nodesToEndNode() == 6);

    test.setCurrentAction("move to the dining room");
    REQUIRE(test.nodesToEndNode() == 5);

    test.setCurrentAction("read the book on the coffee table");
    REQUIRE(test.nodesToEndNode() == 4);

    test.setCurrentAction("go upstairs");
    REQUIRE(test.nodesToEndNode() == 3);

    test.setCurrentAction("go to the bedroom");
    REQUIRE(test.nodesToEndNode() == 2);

    test.setCurrentAction("move to the living room");
    REQUIRE(test.nodesToEndNode() == 6);

    test.setCurrentAction("go to the laundry room");
    REQUIRE(test.nodesToEndNode() == 5);

    test.setCurrentAction("go up the ladder");
    REQUIRE(test.nodesToEndNode() == 4);

    test.setCurrentAction("go to the hallway");
    REQUIRE(test.nodesToEndNode() == 3);

    test.setCurrentAction("check the bedroom");
    REQUIRE(test.nodesToEndNode() == 2);

    test.setCurrentAction("check the drawer");
    REQUIRE(test.nodesToEndNode() == 1);

    test.setCurrentAction("exit the locked window");
    REQUIRE(test.nodesToEndNode() == 0);
}

TEST_CASE("BFS (TestStory.txt)", "[Michael]") {
    Fork test("TestStory.txt");
    REQUIRE(test.nodesToEndNode() == 4);

    test.setCurrentAction("topmid");
    REQUIRE(test.nodesToEndNode() == 3);

    test.setCurrentAction("topright");
    REQUIRE(test.nodesToEndNode() == 2);

    test.setCurrentAction("midleft");
    REQUIRE(test.nodesToEndNode() == 3);

    test.setCurrentAction("midmid");
    REQUIRE(test.nodesToEndNode() == 2);

    test.setCurrentAction("midright");
    REQUIRE(test.nodesToEndNode() == 1);

    test.setCurrentAction("botleft");
    REQUIRE(test.nodesToEndNode() == 2);

    test.setCurrentAction("botmid");
    REQUIRE(test.nodesToEndNode() == 1);

    test.setCurrentAction("botright");
    REQUIRE(test.nodesToEndNode() == 0);
}

TEST_CASE("test restart",  "[Michael]") {
    Fork test("TestStory.txt");

    test.setCurrentAction("botright");
    test.restart();
    REQUIRE(test.getCurrentAction() == "topleft");
}

TEST_CASE("test =operator", "[Michael]") {
    Fork left("TestStory.txt");
    Fork right("semi-complex-story.txt");

    right = left;

    // REQUIRE(right.getAdj_() == left.getAdj_());
    REQUIRE(right.getCurrentAction() == left.getCurrentAction());
    REQUIRE(right.getCurrentActions() == left.getCurrentActions());
    REQUIRE(right.getEndingAction() == left.getEndingAction());
    REQUIRE(right.getNodeInfo() == left.getNodeInfo());
    REQUIRE(right.getStartingAction() == left.getStartingAction());

}