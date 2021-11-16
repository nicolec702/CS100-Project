#ifndef __QUEST_HPP__
#define __QUEST_HPP__

class Quest : public InformationCharacter {

    private:
        string questInfo;
        List<string> dialogueLines;

    public:
        void getInfo(File);
        void setQuestInfo(string);
        void setDialogueLines(List<string> );

        string getQuestInfo();
        void getDialogueLines();

};

#endif // __QUEST_HPP__
