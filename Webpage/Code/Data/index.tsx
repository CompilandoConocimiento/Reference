import NumberTheory from './NumberTheory'
import Search from './Search'
import DynamicProgramming from './DynamicProgramming'
import Strings from './Strings'
import {Topic, SubTopic} from "./types"
import Directory from "./Directory"

//import SaveData from "./UpdateDirectory"

export const Topics: Array<Topic> = [
    NumberTheory,
    DynamicProgramming,
    Search,
    Strings,
]

//SaveData(Topics, "Directory.json")

export type TopicInterface = Topic
export type SubTopicInterface = SubTopic
export const DirectoryData = Directory
