#ifndef CATCH_CONFIG_MAIN
#  define CATCH_CONFIG_MAIN
#endif

#include <catch/catch.hpp>
#include <fork.hpp>

TEST_CASE("constructor, getters, trim", "[Michael]") {
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

    REQUIRE(test.getStartingAction() == "topleft");
    REQUIRE(test.getCurrentAction() == "topleft");
    REQUIRE(test.getEndingAction() == "botright");
}