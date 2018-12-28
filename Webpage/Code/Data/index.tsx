import NumberTheory from './NumberTheory'
import Search from './Search'
import DynamicProgramming from './DynamicProgramming'
import Strings from './Strings'
import {Topic, SubTopic} from "./types"

//import SaveData from "./UpdateDirectory"

const Topics: Array<Topic> = [
    NumberTheory,
    DynamicProgramming,
    Search,
    Strings,
]

//SaveData(Topics, "Directory.json")

export type TopicInterface = Topic
export type SubTopicInterface = SubTopic

export default Topics