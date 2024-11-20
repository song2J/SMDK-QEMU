import asyncio
from qemu.qmp import QMPClient
import json
import sys

async def main():
    argv = sys.argv

    qmp = QMPClient('FEMU')
    await qmp.connect((argv[1], argv[2]))

    command = 'femu-get-ssd-rwe-count'
    data = {'path':argv[3]}
    
    res = await qmp.execute(command, data)
    print('Flash Read  cnt:\t\t', res['ssd-read-count'])
    print('Flash Write cnt:\t\t', res['ssd-write-count'])
    print('Flash Erase cnt:\t\t', res['ssd-erase-count')
    #print('Write Amplification Factor(WAF):', res['write-amplification-factor'])
    #print('Hit-Miss Ratio:\t\t\t', res['hit-miss-ratio'])
    await qmp.disconnect()

asyncio.run(main())
